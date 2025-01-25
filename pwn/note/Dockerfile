FROM ubuntu:20.04

RUN apt-get update && apt-get install -y gcc make libc6-dev-i386 socat && rm -rf /var/lib/apt/lists/*

RUN useradd -m ctf

WORKDIR /home/ctf

COPY challenge.c Makefile flag.txt entrypoint.sh ./

RUN make && chown ctf:ctf challenge && chmod 4755 challenge

RUN mv flag.txt /flag.txt && chmod 600 /flag.txt && chown root:root /flag.txt

EXPOSE 1234

ENTRYPOINT ["./entrypoint.sh"]
