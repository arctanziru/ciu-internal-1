#!/bin/bash
if [ -f /home/ctf/flag.txt ]; then
    mv /home/ctf/flag.txt /flag.txt
    chmod 600 /flag.txt
    chown root:root /flag.txt
fi

chmod +x /home/ctf/elpatron

echo "Challenge is running on port 3131..."
exec socat TCP-LISTEN:3131,reuseaddr,fork EXEC:/home/ctf/elpatron,stderr