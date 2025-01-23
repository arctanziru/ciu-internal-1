using System.Security.Cryptography;
using System.Text;

namespace PagarPagar;

internal static class AesEncryption
{
    private const string Key = "y3NqUnA0sP1ZkQUlOUDBho0hXfNjVgbD";
    private const string Iv = "pxfgpPAqq3YwCCHn";

    private static void EncryptToFile(string plainText, string filePath)
    {
        using var aes = Aes.Create();
        aes.Key = Encoding.UTF8.GetBytes(Key);
        aes.IV = Encoding.UTF8.GetBytes(Iv);

        using var encryptor = aes.CreateEncryptor(aes.Key, aes.IV);
        using var fileStream = new FileStream(filePath, FileMode.Create);
        using var cryptoStream = new CryptoStream(fileStream, encryptor, CryptoStreamMode.Write);
        using var writer = new StreamWriter(cryptoStream);
        writer.Write(plainText);
    }

    private static void Main()
    {
        const string filePath = "aes.enc";

        Console.Write("Enter text to encrypt with AES: ");
        var plainText = Console.ReadLine();
        if (plainText == null)
        {
            Console.WriteLine("Text is empty!");
            return;
        }

        EncryptToFile(plainText, filePath);
        Console.WriteLine($"Data encrypted and written to file: {filePath}");
    }
}