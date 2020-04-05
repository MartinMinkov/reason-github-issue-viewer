module IssueType = {
  type t =
    | All
    | Open
    | Closed
    | PullRequest;

  let statusOfIssue = (issue: IssueData.issue) =>
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