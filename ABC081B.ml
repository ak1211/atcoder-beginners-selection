(* ABC081B - Shift only *)

let even x = x mod 2 = 0

let half x = x / 2

let rec solver = function
  | xs when List.for_all even xs -> 1 + solver (List.map half xs)
  | _ -> 0

let () =
  let _ = read_int () in
  read_line ()
  |> Str.split (Str.regexp " ")
  |> List.map int_of_string |> solver |> string_of_int |> print_endline
