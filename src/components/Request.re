module API = {
  open Json.Decode;
  let baseUrl = "https://api.github.com/repos/";

  let getIssues = query => {
    let url =
      baseUrl
      ++ query.Searchbar.owner
      ++ "/"
      ++ query.Searchbar.repo
      ++ "/issues?state=all&per_page=50";
    Js.Promise.(
      Fetch.fetch(url)
      |> then_(Fetch.Response.json)
      |> then_(json => IssueData.Decode.decodeIssues(json) |> resolve)
    );
  };
};