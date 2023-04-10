defmodule Keygen do
  @number_of_triples_after_dash 3

  def generate(keys_qty) do
    for x <- 1..9, y <- 1..9, z <- 1..9 do
      before_dash = [x, y, z]

      after_dash =
        for a <- 1..9, b <- 1..9, c <- 1..9 do
          [a, b, c]
        end
        |> Enum.chunk_every(@number_of_triples_after_dash)

      [before_dash, after_dash]
      # Enum.join([before_dash, after_dash], "-")
    end
    |> Enum.map(fn [before_dash, after_dash_candidates] ->
      after_dash =
        Enum.filter(after_dash_candidates, fn after_dash ->
          check_triple(before_dash, after_dash, 0) and
            check_triple(before_dash, after_dash, 1) and
            check_triple(before_dash, after_dash, 2)
        end)

      case after_dash == [] do
        true -> nil
        false -> [before_dash | after_dash]
      end
    end)
    |> Enum.reject(&is_nil/1)
    |> Enum.flat_map(fn [before_dash | after_dash_list] ->
      Enum.map(after_dash_list, fn after_dash ->
        before_dash = Integer.undigits(before_dash)
        after_dash = after_dash |> Enum.map(&Integer.undigits/1) |> Enum.join("")

        [before_dash, after_dash]
      end)
    end)
    |> Enum.map(&Enum.join(&1, "-"))
    |> Enum.take_random(keys_qty)
    |> Enum.join("\n")
    |> IO.puts()
  end

  def check_triple(before_dash, after_dash, idx) do
    digit = Enum.at(before_dash, idx)
    before_sum = Enum.sum(before_dash)

    after_sum =
      after_dash
      |> Enum.at(idx)
      |> Enum.sum()

    Bitwise.bxor(digit, rem(before_sum, 3)) == rem(after_sum, 9)
  end
end

case System.argv() do
  [number] ->
    number
    |> String.to_integer()

  [] ->
    10
end
|> Keygen.generate()
