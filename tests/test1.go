package main

import "fmt"
import leto "github.com/alkresin/letogo"

func main() {

	var pconn uint64
	var pt uint64
	//var baVal []byte

	if leto.Init() == 1 {
		fmt.Println("Start!")
		pconn = leto.Connect("127.0.0.1", 2812)
		if pconn != 0 {
			fmt.Println("Done!")
			fmt.Println(leto.GetServerVer(pconn))

			pt = leto.CreateTable( pconn, "/temp/gotest", "GOTEST",
				"NAME;C;10;0;NUM;N;4;0;INFO;C;32;0;", 0 )
			if pt != 0 {

				leto.Append(pt)
				leto.PutFieldString(pt,1,"Alexander")
				leto.PutFieldInt(pt,2,1001)
				leto.PutFieldString(pt,3,"First info string")
				leto.PutRecord(pt)

				leto.Append(pt)
				leto.PutFieldString(pt,1,"Ivan")
				leto.PutFieldInt(pt,2,1003)
				leto.PutFieldString(pt,3,"Second info string")
				leto.PutRecord(pt)

				leto.Append(pt)
				leto.PutFieldString(pt,1,"Petr")
				leto.PutFieldInt(pt,2,1002)
				leto.PutFieldString(pt,3,"Third info string")
				leto.PutRecord(pt)

				leto.CreateOrder( pt, "NUM", "Str(NUM,4)" )

				leto.CloseTable(pt)
			}

			pt = leto.OpenTable(pconn, "/temp/gotest", "TEST1", false, false)
			if pt != 0 {
				leto.GoTop(pt, "NUM")

				fmt.Println("Opened, records:", leto.RecCount(pt))
				fmt.Println("Current record:", leto.RecNo(pt))
				fmt.Println("Name:", string(leto.GetField(pt, 1)))
				fmt.Println("Num:", leto.GetFieldInt(pt, 2))
				fmt.Println("Info:", string(leto.GetField(pt, 3)))

				baVal := ([]byte)("FirstRec")
				leto.PutField(pt, 3, baVal)
				leto.PutRecord(pt)
				fmt.Println("New Info:", string(leto.GetField(pt, 3)))

				leto.Skip(pt, 1, "NUM")
				fmt.Println("Current record:", leto.RecNo(pt))
				fmt.Println("Name:", string(leto.GetField(pt, 1)))
				fmt.Println("Num:", leto.GetFieldInt(pt, 2))
				fmt.Println("Info:", string(leto.GetField(pt, 3)))
			}
		}
		fmt.Println("End")

		leto.Exit()
	}

}
