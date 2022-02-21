import streams
import sequtils
import strutils
import strformat
import strscans
import math
import algorithm
import tables

#[
type ufTree {.header:"<atcoder/dsu>",importcpp:"atcoder::dsu".} = object
proc mkUfTree(n:cint):ufTree {.importcpp:"atcoder::dsu(@)",constructor.}
proc merge(uf:ufTree,a,b:cint):void {.importcpp:"#.merge(@)"}
proc same(uf:ufTree,a,b:cint):bool {.importcpp:"#.same(@)"}
]#

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

proc getLine():seq[int] =
        return stdin.readLine.split.map parseInt
proc getInt():int =
        return stdin.readLine.parseInt




