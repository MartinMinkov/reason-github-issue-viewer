type issue = {
  id: int,
  title: string,
  description: string,
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
    description: json |> field("body", string),
    url: json |> field("html_url", string),
    state: json |> field("state", string),
    pullRequest: json |> optional(field("pull_request", dict(string))),
    labels: json |> field("labels", array(field("name", string))),
  };

  let decodeIssues = array(issue);
};