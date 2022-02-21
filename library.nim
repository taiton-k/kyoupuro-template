import sequtils
import strutils
import strformat
import math
import algorithm

# エラトステネスの篩
proc genPrime(n:int):seq[bool]=
  var result = newSeq[bool](n+1)
  result.fill(true)

  result[0]=false
  result[1]=false

  for i in 2..int sqrt(float n):
    if not result[i]:
      continue

    var j=2
    while i*j <= n:
      result[i*j]=false
      j+=1

  return result

# 素因数分解
proc primeFactorization(n:int):seq[int]=
  var n:int=n
  var result:seq[int]

  var i:int=2
  while i<=int sqrt(float n):
    if n.mod(i)!=0:
      i+=1
    else:
      n=n.div(i)
      result.add(i)

  if n!=1:
    result.add(n)

  return result
