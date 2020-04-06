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

let iconOfStatus = (status: Types.IssueType.t): React.element => {
  Types.IssueType.(
    switch (status) {
    | Open => ReasonReact.null
    | Closed => <IssueClosed height="2rem" width="2rem" />
    | PullRequest => <IssuePullRequest height="2rem" width="2rem" />
    | All => ReasonReact.null
    }
  );
};

[@react.component]
let make = (~issues: array(Types.Issue.t)) => {
  <div className="issue-list-container">
    {if (Array.length(issues) > 0) {
       issues
       |> Array.map(issue =>
            <IssueCard
              key={string_of_int(issue.id)}
              issue
              icon={issue |> Types.IssueType.statusOfIssue |> iconOfStatus}
            />
          )
       |> ReasonReact.array;
     } else {
       ReasonReact.null;
     }}
  </div>;
};