(* ABC049C - 白昼夢 *)

let words = List.map Str.regexp [ "dream"; "dreamer"; "erase"; "eraser" ]

let solver str =
  let rec go = function
    | idx when idx = String.length str -> true
    | idx ->
      List.map
        (function
          | r when Str.string_match r str idx -> go (Str.match_end ())
          | _ -> false)
        words
      |> List.exists (( = ) true)
  in
  if go 0 then "YES" else "NO"

let () = read_line () |> solver |> print_endline
