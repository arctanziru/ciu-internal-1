#!/bin/bash
if [ -f /home/ctf/flag.txt ]; then
    mv /home/ctf/flag.txt /flag.txt
    chmod 600 /flag.txt
    chown root:root /flag.txt
fi

chmod +x /home/ctf/challenge

echo "Challenge is running on port 1234..."
exec socat TCP-LISTEN:1234,reuseaddr,fork EXEC:/home/ctf/challenge,stderr
