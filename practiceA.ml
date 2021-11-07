(* Welcome to AtCoder *)

let () =
  let a = read_int () in
  let b, c = Scanf.sscanf (read_line ()) "%d %d" (fun x y -> (x, y)) in
  let s = read_line () in
  Printf.printf "%d %s" (a + b + c) s
