package main

import (
	"context"
	"log"
	"net"

	pb "example.com/code_examples/protobuf/internal/api/proto/service/v1"
	"google.golang.org/grpc"
)

type server struct {
	pb.UnimplementedEchoServiceServer
}

func (s *server) Echo(ctx context.Context, req *pb.EchoRequest) (*pb.EchoResponse, error) {
	return &pb.EchoResponse{Message: "Echo: " + req.Message}, nil
}

func main() {
	list, err := net.Listen("tcp", ":5051")
	if err != nil {
		log.Fatal(err)
	}

	grpcServer := grpc.NewServer()
	pb.RegisterEchoServiceServer(grpcServer, &server{})

	log.Println("Server is running on port 5051")
	if err := grpcServer.Serve(list); err != nil {
		log.Fatal(err)
	}
}
