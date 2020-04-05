[%bs.raw {|require("./Issue.css")|}];

module IssueClosed = {
  [@bs.module "../../assets/icons/issue-closed.svg"] [@react.component]
  external make: (~height: string, ~width: string) => React.element =
    "default";
};

module IssuePullRequest = {
  [@bs.module "../../assets/icons/pull-request.svg"] [@react.component]
  external make: (~height: string, ~width: string) => React.element =
    "default";
};

let iconOfStatus = (status: Types.IssueStatus.t) => {
  switch (status) {
  | Open => ReasonReact.null
  | Closed => <IssueClosed height="2rem" width="2rem" />
  | PullRequest => <IssuePullRequest height="2rem" width="2rem" />
  };
};

[@react.component]
let make = (~issues: array(IssueData.issue)) => {
  <div className="issue-list-container">
    {if (Array.length(issues) > 0) {
       issues
       |> Array.map(issue =>
            <IssueCard
              key={string_of_int(issue.id)}
              issue
              icon={issue |> Types.IssueStatus.statusOfIssue |> iconOfStatus}
            />
          )
       |> ReasonReact.array;
     } else {
       ReasonReact.null;
     }}
  </div>;
};