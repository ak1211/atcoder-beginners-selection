(* ABC088B - Card Game for Two *)

let solver _ xs =
  let reversed = List.sort (fun x y -> compare y x) xs in
  let f (counter, alice, bob) x =
    if counter mod 2 = 0 then (succ counter, alice + x, bob)
    else (succ counter, alice, bob + x)
  in
  let counter, alice, bob = List.fold_left f (0, 0, 0) reversed in
  alice - bob

let () =
  let n = read_int () in
  read_line ()
  |> Str.split (Str.regexp " ")
  |> List.map int_of_string |> solver n |> string_of_int |> print_endline
