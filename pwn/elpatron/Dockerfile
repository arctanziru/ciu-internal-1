FROM ubuntu:20.04

RUN apt-get update && apt-get install -y gcc make socat libc6-i386

RUN useradd -m ctf

WORKDIR /home/ctf

COPY elpatron.c flag.txt entrypoint.sh elpatron ./ 

RUN chown ctf:ctf elpatron && chmod 4755 elpatron

RUN mv flag.txt /flag.txt && chmod 600 /flag.txt && chown root:ctf /flag.txt

EXPOSE 3131

ENTRYPOINT ["./entrypoint.sh"]