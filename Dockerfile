FROM ubuntu:26.04 AS builder
WORKDIR /usr/app
RUN apt-get update -y
RUN apt-get install --no-install-recommends -y build-essential
COPY ./src ./src
COPY ./include ./include
COPY ./Makefile .
RUN make
RUN make clean

FROM scratch
WORKDIR /usr/app
COPY --from=builder /usr/app/xml.out .
CMD ["./xml.out"]
