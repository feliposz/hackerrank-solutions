package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

// Complete the jumpingOnClouds function below.
func jumpingOnClouds(c []int32) int32 {
    //fmt.Println("clouds ahead ->", c)
    if len(c) == 0 {
        //fmt.Println("can't jump")
        return 0
    }
    if len(c) > 2 {
        if c[1] == 0 && c[2] == 0 {
            //fmt.Println("jump 2 clouds ahead")
            return 1 + jumpingOnClouds(c[2:])
        }
        if c[1] == 1 && c[2] == 0 {
            //fmt.Println("jump 2 clouds ahead")
            return 1 + jumpingOnClouds(c[2:])
        }
        if c[1] == 0 && c[2] == 1 {
            //fmt.Println("jump 1 cloud ahead")
            return 1 + jumpingOnClouds(c[1:])
        }
    }
    if len(c) == 2 {
        if c[1] == 0 {
            //fmt.Println("jump 1 cloud ahead")
            return 1 + jumpingOnClouds(c[2:])
        }
        if c[1] == 1 {
            panic("dead end")
        }
    }
    if len(c) == 1 {
        if c[0] == 0 {
            return 0
        }
        panic("what!")
    }
    return 999
}


func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 1024 * 1024)

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int32(nTemp)

    cTemp := strings.Split(readLine(reader), " ")

    var c []int32

    for i := 0; i < int(n); i++ {
        cItemTemp, err := strconv.ParseInt(cTemp[i], 10, 64)
        checkError(err)
        cItem := int32(cItemTemp)
        c = append(c, cItem)
    }

    result := jumpingOnClouds(c)

    fmt.Fprintf(writer, "%d\n", result)

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}

