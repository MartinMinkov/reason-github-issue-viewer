module CloseIcon = {
  [@bs.module "../../assets/icons/close.svg"] [@react.component]
  external make: (~height: string) => React.element = "default";
};

let listTitles = [|
  Types.IssueType.All,
  Types.IssueType.Open,
  Types.IssueType.Closed,
  Types.IssueType.PullRequest,
|];

[@react.component]
let make = (~onFilterPress, ~current) => {
  let renderListItem = title => {
    let text = Types.IssueType.stringOfIssue(title);
    let className =
      title == current
        ? "issue-filter-item issue-filter-item-active" : "issue-filter-item";
    <div key=text className onClick={_ => onFilterPress(title)}>
      {text |> ReasonReact.string}
    </div>;
  };

  <div className="issue-filter-container">
    {listTitles->Belt.Array.map(title => renderListItem(title)) |> React.array}
    <div
      onClick={_ => ReasonReactRouter.push("/")}
      className="issue-filter-icon">
      <CloseIcon height="2rem" />
    </div>
  </div>;
};