package main

import "fmt"
import "github.com/alkresin/letoGo"

func main() {

	var pconn uint64
	var pt uint64
	var baVal []byte

	if letoGo.Init() == 1 {
		fmt.Println("Start!")
		pconn = letoGo.Connect("127.0.0.1", 2812)
		if pconn != 0 {
			fmt.Println("Done!")
			fmt.Println(letoGo.GetServerVer(pconn))

			pt = letoGo.OpenTable(pconn, "/temp/test1", "TEST1", false, false)
			if pt != 0 {
				letoGo.GoTop(pt, "")

				fmt.Println("Opened, records:", letoGo.RecCount(pt))
				fmt.Println("Current record:", letoGo.RecNo(pt))
				fmt.Println("Name:", string(letoGo.GetField(pt, 1)))
				fmt.Println("Num:", letoGo.GetFieldInt(pt, 2))
				fmt.Println("Info:", string(letoGo.GetField(pt, 3)))

				baVal = ([]byte)("FirstRec")
				letoGo.PutField(pt, 3, baVal)
				letoGo.PutRecord(pt)
				fmt.Println("New Info:", string(letoGo.GetField(pt, 3)))

				letoGo.GoTo(pt, 2, "")
				fmt.Println("Current record:", letoGo.RecNo(pt))
				fmt.Println("Name:", string(letoGo.GetField(pt, 1)))
				fmt.Println("Num:", letoGo.GetFieldInt(pt, 2))
				fmt.Println("Info:", string(letoGo.GetField(pt, 3)))
			}
		}
		fmt.Println("End")

		letoGo.Exit()
	}

}
