(* ABC086C - Traveling *)

let distance (t, x, y) (t', x', y') = (abs (t - t'), abs (x - x') + abs (y - y'))

let solver inputs =
  let tmp = ref (0, 0, 0) in
  try
    for idx = 0 to Array.length inputs - 1 do
      let t, d = distance inputs.(idx) !tmp in
      tmp := inputs.(idx);
      if t >= d && (t - d) mod 2 = 0 then () else raise Not_found
    done;
    "Yes"
  with Not_found -> "No"

let () =
  let n = read_int () in
  Array.init n (fun _ ->
      Scanf.sscanf (read_line ()) "%d %d %d" (fun t x y -> (t, x, y)))
  |> solver |> print_endline
