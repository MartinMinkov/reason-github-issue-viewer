[%bs.raw {|require("./Header.css")|}];

[@react.component]
let make = (~query) => {
  let url =
    "https://github.com/"
    ++ query.Searchbar.owner
    ++ "/"
    ++ query.Searchbar.repo;

  <div className="header-container">
    <h1 onClick={_ => ReasonReactRouter.push("/")} className="header-title">
      {"Github Issue Viewer" |> ReasonReact.string}
    </h1>
    <a href=url>
      <h2 className="header-website"> {url |> ReasonReact.string} </h2>
    </a>
  </div>;
};