// 云函数入口文件
const cloud = require('wx-server-sdk')
cloud.init({
  env:cloud.DYNAMIC_CURRENT_ENV
})
// 云函数入口函数
exports.main = async (event, context) => {
if(event.action=='fabiao'){
  return await cloud.database().collection("homelist").doc(event.id)
  .update({
    data:{
      pinglun:event.pinglun//更改评论列表的
    }
  })
  .then(res=>{
    console.log("评论成功",res)
    return res
  })
  .catch(res=>{
    console.log("评论失败",res)
    return res
  })

  
  }
  

}