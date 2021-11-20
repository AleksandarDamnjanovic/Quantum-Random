#******************************************
#Title: Quantum Random
#Author: Aleksandar Damnjanovic
#Date: 19.11.2021
#Last edit: 20.11.2021
#******************************************

library("httr") 
library("jsonlite")

nextOne<-function(){
  addr<-GET("https://qrng.anu.edu.au/API/jsonI.php?length=1&type=hex16&size=4")
  page<-content(addr,"text")
  json<-fromJSON(page, flatten = TRUE)
  json<-as.data.frame(json)
  val<-json$data
  val<-paste0('0x', val)
  val<-as.numeric(val)
  val<-sprintf("%.0f", val)
  Sys.sleep(.5)
  return(val)
}

getRand<-function(minv, maxv){
  bigVal<-nextOne()
  bigVal<-as.numeric(bigVal)
  minv<-as.numeric(minv)
  maxv<-as.numeric(maxv)
  
  if(minv<0 || maxv>.Machine$integer.max)
    print(paste('min must be bigger than or0;', 'max must be less than', .Machine$integer.max))

  ret<-0
  con<-(bigVal>maxv)
  if(maxv!=.Machine$integer.max)
    if(con)
      ret<-bigVal %% maxv
  
  if(ret<minv && minv!=0)
    ret= minv + (bigVal %% (maxv-minv))
  
  ret<-sprintf("%.0f", ret)
  return(ret)  
}

getFloat<-function(decimal){
  ret<-getRand(0,1000)
  ret<-as.numeric(ret)
  ret<- as.double(ret/1000)
  f<-paste0('%.',decimal,'f')
  ret<-sprintf(f, ret)
  return(ret)
}