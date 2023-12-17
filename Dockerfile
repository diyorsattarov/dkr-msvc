# Use a base image with a C++ environment
FROM debian:11

# Install g++, make, cmake, git, and libevent libraries
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    cmake \
    git \
    libevent-dev
    # libboost-all-dev

# Set the working directory for the application
WORKDIR /app

# Copy the source code and the Makefile
COPY . /app

# Build the application
RUN cmake . && make all

# Expose the port the app runs on
EXPOSE 8080

# Command to run the executable
CMD ["./microservice"]
