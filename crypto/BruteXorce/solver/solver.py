from pwn import *
import base64

ct= "b2pqKSl+ZmpmdG5vamZyY25jYmRoY2JuaW5rZmBuKjlOSUJRTEpVVkBONV9QNTRXSUlXUEhJQ0lIRjVAM101MEpONUAzXV1TSFVXX1RJRTBPMzBTMVc0Mg=="

ct = base64.b64decode(ct)
ct = "ojj))~fjftnojfrcncbdhcbninkf`n*9NIBQLJUV@N5_P54WIIWPHICIHF5@3]50JN5@3]]SHUW_TIE0O30S1W42"

for i in range(0, 255):
    try:
        # Key = 7
        decoded = xor(i.encode(), ct).decode()
    except:
        pass

# hmm..yamasihmaudidecodeinilagi->INEVKMRQGI2XW23PNNPWONDNOA2G4Z27MI2G4ZZTORPXSNB7H47T6P35
another_c = "INEVKMRQGI2XW23PNNPWONDNOA2G4Z27MI2G4ZZTORPXSNB7H47T6P35"
ans = base64.b32decode(another_c)
print(ans.decode())