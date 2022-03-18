// 云函数代码
const cloud = require('wx-server-sdk')
cloud.init({
  env: cloud.DYNAMIC_CURRENT_ENV
})
exports.main = async (event, context) => {
  const res = await cloud.cloudPay.unifiedOrder({
    "body" : "来自某人的一笔手续费",//商品名称 或商品描述
    "outTradeNo" : "0625"+new Date().getTime(),//订单号
    "spbillCreateIp" : "127.0.0.1",
    "subMchId" : "1620013224",//微信支付商务号
    "totalFee" :100,//支付的钱。按分来算
    "envId": "cloud1-7gp41k08a5f40651",
    "functionName": "payCallBack"//支付成功的回调
  })
  return res
}