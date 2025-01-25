#!/bin/bash
if [ -f /home/ctf/flag.txt ]; then
    mv /home/ctf/flag.txt /flag.txt
    chmod 600 /flag.txt
    chown root:root /flag.txt
fi

chmod +x /home/ctf/challenge

# disable ASLR
echo "Challenge is running on port 6789..."
exec socat TCP-LISTEN:6789,reuseaddr,fork EXEC:/home/ctf/challenge,stderr
