package main

import (
	"context"
	"log"
	"net"
	"time"

	pb "example.com/code_examples/protobuf/internal/api/proto/service/v1"
	"google.golang.org/grpc"
	"google.golang.org/grpc/reflection"
)

type server struct {
	pb.UnimplementedEchoServiceServer
}

func (s *server) Echo(ctx context.Context, req *pb.EchoRequest) (*pb.EchoResponse, error) {
	return &pb.EchoResponse{
		Message: "Echo: " + req.Message,
		Time:    time.Now().Format(time.RFC3339),
		Ip:      "",
	}, nil
}

func main() {
	list, err := net.Listen("tcp", ":5051")
	if err != nil {
		log.Fatal(err)
	}

	grpcServer := grpc.NewServer()
	reflection.Register(grpcServer)
	pb.RegisterEchoServiceServer(grpcServer, &server{})

	log.Println("Server is running on port 5051")
	if err := grpcServer.Serve(list); err != nil {
		log.Fatal(err)
	}
}
