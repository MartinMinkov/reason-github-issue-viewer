module Issue = {
  type t = {
    id: int,
    title: string,
    description: option(string),
    url: string,
    state: string,
    pullRequest: option(Js.Dict.t(string)),
    labels: array(string),
  };

  module Decode = {
    open Json.Decode;

    let issue = json => {
      id: json |> field("id", int),
      title: json |> field("title", string),
      description: json |> optional(field("body", string)),
      url: json |> field("html_url", string),
      state: json |> field("state", string),
      pullRequest: json |> optional(field("pull_request", dict(string))),
      labels: json |> field("labels", array(field("name", string))),
    };

    let decodeIssues = array(issue);
  };
};

module IssueType = {
  type t =
    | All
    | Open
    | Closed
    | PullRequest;

  let stringOfIssue = (issueType: t): string =>
    switch (issueType) {
    | All => "All Issues"
    | Open => "Open Issues"
    | Closed => "Closed Issues"
    | PullRequest => "Pull Requests"
    };

  let issueTypeOfIssue = (issue: Issue.t): t =>
    if (issue.state == "closed") {
      Closed;
    } else if (issue.state == "open" && issue.pullRequest == None) {
      Open;
    } else if (issue.pullRequest != None) {
      PullRequest;
    } else {
      All;
    };
};