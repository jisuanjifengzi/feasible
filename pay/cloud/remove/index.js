// 云函数入口文件
const cloud = require('wx-server-sdk')

cloud.init()

// 云函数入口函数
exports.main = async (event, context) => {
  // const wxContext = cloud.getWXContext()
let {collectionName,where}=event;
  return new Promise((resolve,reject)=>{
    db.collection(collectionName).where(where).remove().then(res=>{
      resolve(res);
    })
    .catch(err=>{
      reject(err)
    })
  })
}
