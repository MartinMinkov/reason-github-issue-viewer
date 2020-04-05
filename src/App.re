[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let onSearch = query => {
    "/issues/"
    ++ query.Searchbar.owner
    ++ "/"
    ++ query.Searchbar.repo
    |> ReasonReactRouter.push;
  };

  switch (url.path) {
  | [] => <Searchbar onSearch />
  | ["issues", owner, repo] =>
    <Issues query={Searchbar.owner, Searchbar.repo} />
  | _ => <Searchbar onSearch />
  };
};