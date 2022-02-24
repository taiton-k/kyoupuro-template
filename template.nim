import system
import streams
import sequtils
import strutils
import strformat
import strscans
import math
import algorithm
import tables
import hashes
import intsets
import sets

const useCppFeat = false

when useCppFeat:
        {.passc:"-std=gnu++17 -Wall -Wextra -O2 -DONLINE_JUDGE -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -I/opt/ac-library".}

        type dsu {.header:"<atcoder/dsu>",importcpp:"atcoder::dsu".} = object
        proc mkDsu(n:int):dsu {.importcpp:"atcoder::dsu(@)",constructor.}
        proc merge(uf:dsu,a,b:int):void {.importcpp:"#.merge(@)"}
        proc same(uf:dsu,a,b:int):bool {.importcpp:"#.same(@)"}

        type mint {.header:"<atcoder/modint>",importcpp:"atcoder::modint1000000007".} = object
        proc val(a:mint):int {.importcpp:"#.val()"}
else:
        {.passc:"-Wall -Wextra -Ofast -DONLINE_JUDGE"}

proc yorn(flag:bool):void=
        echo if flag: "Yes" else: "No"
proc `/`(n:int,x:int):int=
        return n.div(x)
proc `/=`(n:var int,x:int):void=
        n=n.div(x)
proc `++`(n:var int):void=
        n+=1
proc `--`(n:var int):void=
        n-=1

type point = seq[int]
proc newPoint():seq[int] = newSeq[int](2)
proc x(p:point):int = p[0]
proc y(p:point):int = p[1]
proc a(p:point):int = p[0]
proc b(p:point):int = p[1]
proc `-`(p:point,q:point):point= @[p.x-q.x,p.y-q.y]
proc `-=`(p:var point,q:point):void=
        p = p-q
proc dist(p:point,q:point):float =
        var p=p
        var q=q
        q-=p
        return sqrt(float(q.x * q.x)+float(q.y * q.y))

proc getLine():seq[int] = stdin.readLine.split.map parseInt
proc getInt():int = stdin.readLine.parseInt
proc print(a: varargs[string, `$`]):void =
        stdout.write(a)

proc main():void
main()




proc main():void =

