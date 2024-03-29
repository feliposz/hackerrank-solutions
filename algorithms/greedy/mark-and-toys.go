package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
    "sort"
)

// Complete the maximumToys function below.
func maximumToys(prices []int32, k int32) int32 {
    p := make([]int, len(prices))
    for i, v := range prices {
        p[i] = int(v)
    }
    sort.Ints(p)
    total := 0
    n := len(p)
    for i := 0; i < n; i++ {
        if total + p[i] > int(k) {
            return int32(i)
        }
        total += p[i]
    }
    return int32(n-1)
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 1024 * 1024)

    nk := strings.Split(readLine(reader), " ")

    nTemp, err := strconv.ParseInt(nk[0], 10, 64)
    checkError(err)
    n := int32(nTemp)

    kTemp, err := strconv.ParseInt(nk[1], 10, 64)
    checkError(err)
    k := int32(kTemp)

    pricesTemp := strings.Split(readLine(reader), " ")

    var prices []int32

    for i := 0; i < int(n); i++ {
        pricesItemTemp, err := strconv.ParseInt(pricesTemp[i], 10, 64)
        checkError(err)
        pricesItem := int32(pricesItemTemp)
        prices = append(prices, pricesItem)
    }

    result := maximumToys(prices, k)

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

