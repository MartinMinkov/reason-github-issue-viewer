[%bs.raw {|require("./Issue.css")|}];

[@react.component]
let make = (~issue: IssueData.issue, ~icon: ReasonReact.reactElement) => {
  <div className="issue-card-container">
    <a href={issue.url}>
      <div className="issue-card-title-container">
        <h3 className="issue-card-title-header">
          {issue.title |> ReasonReact.string}
        </h3>
        <div className="issue-card-icon"> icon </div>
      </div>
      <div className="issue-card-description">
        <p className="issue-card-description">
          {if (String.length(issue.description) > 0) {
             issue.description |> ReasonReact.string;
           } else {
             "No description provided" |> ReasonReact.string;
           }}
        </p>
      </div>
      <ul className="issue-card-label-container">
        {issue.labels
         |> Array.map(label => {
              <li key=label className="tag is-danger issue-card-label">
                {label |> ReasonReact.string}
              </li>
            })
         |> ReasonReact.array}
      </ul>
    </a>
  </div>;
};