[%bs.raw {|require("./Searchbar.css")|}];

type query = {
  repo: string,
  owner: string,
};

module SearchIcon = {
  [@bs.module "../../assets/icons/search.svg"] [@react.component]
  external make: (~height: string) => React.element = "default";
};

let formatQuery = (s: string): Js.Array.t(Js.String.t) => {
  let result = Js.String.split("/", s);
  [|Js.Array.pop(result), Js.Array.pop(result)|]
  |> Js.Array.reverseInPlace
  |> Js.Array.map(item => {
       switch (item) {
       | Some(item) => item
       | None => ""
       }
     });
};

[@react.component]
let make = (~onSearch) => {
  let (input, setInput) = React.useState(() => "");

  let onSubmit = e => {
    ReactEvent.Form.preventDefault(e);
    let result = formatQuery(input);
    {owner: result[0], repo: result[1]}->onSearch;
  };

  <div className="search-container">
    <label className="search-container-label">
      {"Github Issue Viewer" |> ReasonReact.string}
    </label>
    <div className="control has-icons-left">
      <form onSubmit className="search-container-form ">
        <input
          className="input is-large"
          type_="text"
          placeholder="Paste a link to a Github repo!"
          onChange={e => setInput(ReactEvent.Form.target(e)##value)}
          value=input
          autoComplete="off"
        />
        <span className="icon is-small is-left">
          <SearchIcon height="2.5rem" />
        </span>
      </form>
    </div>
  </div>;
};