(* ABC085B - Kagami Mochi *)

module IntSet = Set.Make (Int)

let solver stream =
  let rec go sets = function
    | Some s ->
      go
        (IntSet.add (int_of_string s) sets)
        (Stream.junk stream;
         Stream.peek stream)
    | None -> sets
  in
  go IntSet.empty (Stream.peek stream) |> IntSet.cardinal

let () =
  let n = read_int () in
  Stream.from (fun i -> if i < n then Some (read_line ()) else None)
  |> solver |> string_of_int |> print_endline
