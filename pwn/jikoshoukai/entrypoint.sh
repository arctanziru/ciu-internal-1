#!/bin/bash
if [ -f /home/ctf/flag.txt ]; then
    mv /home/ctf/flag.txt /flag.txt
    chmod 600 /flag.txt
    chown root:root /flag.txt
fi

chmod +x /home/ctf/jiko

echo "Challenge is running on port 9988..."
exec socat TCP-LISTEN:9988,reuseaddr,fork EXEC:/home/ctf/jiko,stderr