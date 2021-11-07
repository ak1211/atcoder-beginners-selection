(* ABC087B - Coins *)

let solver a b c x =
  let counter = ref 0 in
  for a' = 0 to a do
    for b' = 0 to b do
      for c' = 0 to c do
        if (500 * a') + (100 * b') + (50 * c') = x then counter := !counter + 1
      done
    done
  done;
  !counter

let () =
  let a = read_int () in
  let b = read_int () in
  let c = read_int () in
  let x = read_int () in
  solver a b c x |> string_of_int |> print_endline
