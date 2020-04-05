[%bs.raw {|require("./Issue.css")|}];

let trimDescription = (s): string => {
  String.length(s) > 250 ? String.sub(s, 0, 250) ++ "..." : s;
};

type state = {
  issues: array(IssueData.issue),
  filterIssueBy: Types.IssueType.t,
};

let initialState = {issues: [||], filterIssueBy: All};

type action =
  | Loaded(array(IssueData.issue))
  | Filtered(Types.IssueType.t);

let reducer = (state, action) => {
  switch (action) {
  | Loaded(repoIssues) =>
    let results =
      Belt.Array.map(repoIssues, issue => {
        {...issue, description: trimDescription(issue.description)}
      });
    {...state, issues: results};
  | Filtered(filterState) => {...state, filterIssueBy: filterState}
  };
};

[@react.component]
let make = (~query) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  let onFilterPress = s => {
    dispatch(Filtered(s));
  };

  let filterIssuesToDisplay = (): array(IssueData.issue) => {
    switch (state.filterIssueBy) {
    | All => state.issues
    | Open =>
      state.issues
      ->Belt.Array.keep(item =>
          item.state == "open" && item.pullRequest == None
        )
    | Closed => state.issues->Belt.Array.keep(item => item.state == "closed")
    | PullRequest =>
      state.issues
      ->Belt.Array.keep(item =>
          item.pullRequest != None && item.state != "closed"
        )
    };
  };

  React.useEffect0(() => {
    let _ =
      Request.API.getIssues(query)
      |> Js.Promise.then_(response => {
           dispatch(Loaded(response));
           Js.Promise.resolve();
         });
    None;
  });

  <div className="issue-container">
    <Header query />
    <IssueFilter onFilterPress />
    <IssueList issues={filterIssuesToDisplay()} />
  </div>;
};