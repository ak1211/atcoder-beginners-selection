(* ABC083B - Some Sums *)

let rec sum_of_digits x =
  if x >= 10 then (x mod 10) + sum_of_digits (x / 10) else x

let solver = function
  | [ n; a; b ] ->
      let test x = a <= x && x <= b in
      let summary = ref 0 in
      for n' = 1 to n do
        if test (sum_of_digits n') then summary := !summary + n'
      done;
      !summary
  | _ -> failwith "?"

let () =
  read_line ()
  |> Str.split (Str.regexp " ")
  |> List.map int_of_string |> solver |> string_of_int |> print_endline
