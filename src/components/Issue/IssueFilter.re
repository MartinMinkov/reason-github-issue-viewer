module CloseIcon = {
  [@bs.module "../../assets/icons/close.svg"] [@react.component]
  external make: (~height: string) => React.element = "default";
};

[@react.component]
let make = (~onFilterPress) => {
  <div className="issue-filter-container">
    <div
      className="issue-filter-item"
      onClick={_ => onFilterPress(Types.IssueType.All)}>
      {"All Issues" |> ReasonReact.string}
    </div>
    <div
      className="issue-filter-item"
      onClick={_ => onFilterPress(Types.IssueType.Open)}>
      {"Open Issues" |> ReasonReact.string}
    </div>
    <div
      className="issue-filter-item"
      onClick={_ => onFilterPress(Types.IssueType.Closed)}>
      {"Closed Issues" |> ReasonReact.string}
    </div>
    <div
      className="issue-filter-item"
      onClick={_ => onFilterPress(Types.IssueType.PullRequest)}>
      {"Pull Issues" |> ReasonReact.string}
    </div>
    <div
      onClick={_ => ReasonReactRouter.push("/")}
      className="issue-filter-icon">
      <CloseIcon height="2rem" />
    </div>
  </div>;
};