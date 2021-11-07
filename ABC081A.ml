(* ABC081A - Placing Marbles *)

let solver s =
  let counter = ref 0 in
  for i = 0 to String.length s - 1 do
    if s.[i] = '1' then incr counter
  done;
  !counter

let () = read_line () |> solver |> string_of_int |> print_endline
