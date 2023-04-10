defmodule Decode do
  @moduledoc """
  Decode strings in task.

  ## Example:

  ```bash
  elixir decode.exs "0x4af2d0d4eeeee890" "0xd2eee8f8f0f0ccea" "0xeed8e6e8904a4a66" "0xe8dcf2cce2f4f2cc" "0x4ce6"
  ```

  will return `Correct password.  Congratulation!`
  """
  import Bitwise

  def run(number_str) do
    number_str
    |> String.replace("0x", "")
    |> String.split(~r/(\w){2}/, include_captures: true, trim: true)
    |> Enum.map(fn num -> (String.to_integer(num, 16) >>> 1) - 5 end)
    |> Enum.reverse()
    |> IO.write()
  end
end

System.argv() |> Enum.each(&Decode.run/1)
