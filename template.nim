import streams
import sequtils
import strutils
import strformat
import strscans
import math
import algorithm
import tables

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

proc getLine():sec[int] = return stdin.readLine.split.map parseInt
proc getInt():int = return stdin.readLine.parseInt

