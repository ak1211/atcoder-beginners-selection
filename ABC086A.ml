(* ABC086A - Product *)

let solver = function
  | [ a; b ] -> if a * b mod 2 = 0 then "Even" else "Odd"
  | _ -> failwith "?"

let () =
  read_line () |> String.split_on_char ' ' |> List.map int_of_string |> solver
  |> print_endline
