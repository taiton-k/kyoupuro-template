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

const useACLFeat = false

when useACLFeat:
        {.passc:"-std=gnu++17 -Wall -Wextra -O2 -DONLINE_JUDGE -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -I/opt/ac-library".}

        type dsu {.header:"<atcoder/dsu>",importcpp:"atcoder::dsu".} = object
        proc mkDsu(n:int):dsu {.importcpp:"atcoder::dsu(@)",constructor.}
        proc merge(uf:dsu,a,b:int):void {.importcpp:"#.merge(@)"}
        proc same(uf:dsu,a,b:int):bool {.importcpp:"#.same(@)"}

        type mint {.header:"<atcoder/modint>",importcpp:"atcoder::modint1000000007".} = object
        proc val(a:mint):int {.importcpp:"#.val()"}
else:
        {.passc:"-std=c++17 -Wall -Wextra -Ofast -DONLINE_JUDGE"}

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

type point = array[2,int]
proc x(p:point):int = p[0]
proc y(p:point):int = p[1]
proc a(p:point):int = p[0]
proc b(p:point):int = p[1]
proc `-`(p:point,q:point):point= [p.x-q.x,p.y-q.y]
proc `-=`(p:var point,q:point):void=
        p = p-q
proc dist(p:point,q:point):float =
        var p=p
        var q=q
        q-=p
        return sqrt(float(q.x * q.x)+float(q.y * q.y))

proc getc():char {.header:"<cstdio>" importcpp:"getchar_unlocked()".}
proc ungetc(c:char):void {.importcpp:"ungetc(@, stdin)".}
const endl:char = '\n'
type inputter = object
let cin:inputter = inputter()
proc `>>`(ist:inputter,s:var string):inputter {.discardable.} =
        var t:string
        var c:char = getc()
        while c == ' ' or c == '\n':
                c = getc()
        while c != ' ' and c != '\n':
                t.add(c)
                c = getc()
        ungetc(c)
        s = t
proc `>>`(ist:inputter,n:var int):inputter {.discardable.} =
        var s:string
        ist >> s
        n = parseInt(s)
        return ist
proc `>>`(ist:inputter,n:var float):inputter {.discardable.} =
        var s:string
        ist >> s
        n = parseFloat(s)
        return ist
proc `>>`[T](ist:inputter,a:var openArray[T]):inputter {.discardable.} =
        for i,_ in pairs(a):
                ist >> a[i]

type outputter = object
        f : File
proc `<<`(ost:outputter,a:string or int or float or char):outputter {.discardable.} =
        ost.f.write($a)
        return ost
proc `<<`[T](ost:outputter,a:openArray[T]):outputter {.discardable.} =
        for i in a:
                ost << i
        ost << endl
        return ost
proc `<<`(ost:outputter,p:proc(f:File)):outputter {.discardable.}=
        p(ost.f)
        return ost
proc flush(f:File):void=
        f.flushFile()
let cout:outputter = outputter(f:stdout)
let cerr:outputter = outputter(f:stderr)

proc main():void
main()




proc main():void =

