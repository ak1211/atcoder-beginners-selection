(* ABC085C - Otoshidama *)

exception Ok of (int * int * int)

let solver (n, y) =
  try
    for a = 0 to n do
      for b = 0 to n - a do
        let c = n - a - b in
        if (10000 * a) + (5000 * b) + (1000 * c) = y then raise (Ok (a, b, c))
      done
    done;
    (-1, -1, -1)
  with
  | Ok a -> a

let () =
  Scanf.sscanf (read_line ()) "%d %d" (fun n y -> (n, y)) |> solver
  |> fun (a, b, c) -> Printf.printf "%d %d %d\n" a b c
