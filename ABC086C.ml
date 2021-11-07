(* ABC086C - Traveling *)

type coord = { x : int; y : int }

let distance a b = abs (a.x - b.x) + abs (a.y - b.y)

let solver (txy : (int * coord) array) =
  let zero = (0, { x = 0; y = 0 }) in
  let walk previous current =
    let dt = fst current - fst previous in
    let dist = distance (snd current) (snd previous) in
    if dt < dist then raise Not_found
    else if (dt - dist) mod 2 = 0 then current
    else raise Not_found
  in
  try Array.fold_left walk zero txy |> Fun.const "Yes" with Not_found -> "No"

let () =
  let n = read_int () in
  let init _ =
    Scanf.sscanf (read_line ()) "%d %d %d" (fun t x y -> (t, { x; y }))
  in
  Array.init n init |> solver |> print_endline
