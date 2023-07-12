Random moneda = new Random();
string tiro = moneda.Next(2) == 0 ? "cara" : "cruz";
Console.Write($"Salió {tiro}");