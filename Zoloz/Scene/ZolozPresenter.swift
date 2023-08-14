//
//  ZolozPresenter.swift
//  Zoloz
//
//  Created by Reynaldo Cristinus Hutahaean on 14/08/23.
//

import UIKit
import CommonZoloz

class ZolozPresenter {
    weak var view: ZolozPresenterToView?
    var interactor: ZolozPresenterToInteractor?
    var router: ZolozPresenterToRouter?
}

extension ZolozPresenter: ZolozViewToPresenter {
    func didTappedButton() {
        print("meta: \(ZLZFacade.getMetaInfo())")
        startZoloz()
    }
    
    func startZoloz() {
        #warning("hardcoded public key and locale still use static value")
        let clientCfg = "{\"clientStartIndex\":1,\"flowId\":\"G000000004e1bd415ebd225cb78f16912b88e490e9\",\"factorContext\":{\"GATEWAY_URL\":\"https://sg-sandbox-api.zoloz.com/zmgs/v2/sec\",\"WORKSPACE_ID\":\"default\",\"APP_ID\":\"ZOLOZ_EKYC_GLOBAL\",\"faceZimId\":\"G000000004e1bd415ebd225cb78f16912b88e490e9\",\"keyHash\":\"0C26BD\",\"merchantId\":\"480\",\"keyMeta\":\"{\\\"resourceCode\\\":\\\"00000000\\\",\\\"mid\\\":\\\"480\\\",\\\"keyVer\\\":\\\"v1\\\"}\",\"zimInitResp\":\"CGQaKkcwMDAwMDAwMDRlMWJkNDE1ZWJkMjI1Y2I3OGYxNjkxMmI4OGU0OTBlOSLIDUNwQUlDaXRITURBd01EQXdNREEwWkRFM09XVTRaalUyWVRWbE1UbGlOMlpsWWpZME1EaGlOelJqWVdVeU5UTmtFR1F5M2dkN0ltTnZiR3dpT25zaVlYVjBhRzl5YVhwaGRHbHZiaUk2Wm1Gc2MyVXNJblZ3Ykc5aFpFMXZibWwwYjNKUWFXTWlPakVzSW14cFoyaDBJam95TURBc0ltRnljbTkzVTNSaFkydFVhVzFsSWpveUxDSm1ZV3hqYjI1RGIyeHNaV04wVkdsdFpTSTZOVEF3TENKMGFXMWxJam95TUN3aWNtVjBjbmtpT2pWOUxDSjFhU0k2SWprNU5DSXNJblZ3Ykc5aFpDSTZleUoxY0d4dllXUmZZMjl0Y0hKbGMzTmZjbUYwWlNJNk1DNDRMQ0pqYjJ4c1pXTjBhVzl1SWpwYklsQmhibThpWFgwc0ltNWhkbWtpT25zaVpXNWhZbXhsSWpwbVlXeHpaWDBzSW5abGNtbG1lVTF2WkdVaU9pSnViM0p0WVd3aUxDSnpZMlZ1WlVWdWRpSTZleUp6WTJWdVpVTnZaR1VpT2lKaGJuUlBjR1Z1SzJGdWRFOXdaVzRyWVhSdmJXbGpLMkYwYjIxcFl5SXNJbk5qWlc1bFZIbHdaU0k2SW01dmNtMWhiQ0o5TENKbGJuWWlPakFzSW1aaFkyVlVhWEJ6SWpwN0ltSnlZVzVrVkdsd0lqb2lJQ0o5TENKaGJHZHZjbWwwYUcwaU9uc2ljRzl6WlY5c2FXZG9kQ0k2TUM0ekxDSndiM05sWDNsaGQwMXBiaUk2TFRBdU1EVXNJbk4wWVdOclgzUnBiV1VpT2pFdU5Td2liRzluWDJ4bGRtVnNJam93TENKbGVXVmZiM0JsYm01bGMzTWlPakF1TWl3aVpYbGxYMjlqWTJ4MWMybHZibDl6WTI5eVpWOTBhSEpsYzJodmJHUWlPakF1TlN3aWJHbDJaVzVsYzNOZllXTjBhVzl1WDJOdmJXSnBibUYwYVc5dUlqcGJleUp1WVcxbElqb2lVMk5oYkdVaUxDSnBibVJsZUNJNk1Dd2lZMjlzYkdWamRHbHZiaUk2V3lKbGVHbG1JaXdpYzJWdWMyOXlJbDBzSW1OdmJtWnBaeUk2ZXlKdGFXUmtiR1ZmYVc5a0lqb3dMakk0TENKdFlYSm5hVzVmYVc5a0lqb3dMakF5Zlgwc2V5SnVZVzFsSWpvaVFteHBibXNpTENKcGJtUmxlQ0k2TVgxZExDSndiM05sWDNCcGRHTm9Jam93TGpBNExDSndiM05sWDNsaGR5STZNQzR3TlN3aWNHOXpaVjluWVhWemMybGhiaUk2TUM0eE5Td2laR0YwWVY5amIyeHNaV04wYVc5dUlqcGJJbVpoY2lJc0ltNWxZWElpTENKbGVXVmZZMnh2YzJVaUxDSnpZM0psWlc0aUxDSmpZVzFsY21GZmNHRnlZVzF6SWwwc0ltMWhlRjlwYjJRaU9qQXVNelVzSW5CMGMxOXZZMk5mYm5WdFgzUm9jbVZ6YUc5c1pDSTZNVEF1TUN3aWMyVmpVSEp2ZEc5amIyd2lPaUlpTENKd2IzTmxYMjF2ZEdsdmJpSTZNQzR3TENKeGRXRnNhWFI1WDIxcGJsOXhkV0ZzYVhSNUlqb3lNQ3dpWW14cGJtdGZiM0JsYm01bGMzTWlPakF1TWl3aWNHOXpaVjl3YVhSamFFMXBiaUk2TFRBdU1EZ3NJbkJ2YzJWZmNtVmpkSGRwWkhSb0lqb3dMakkxTENKd2IzTmxYMmx1ZEdWbmNtbDBlU0k2TUM0NUxDSnRhVzVmYVc5a0lqb3dMakUxZlgwU2dBSVhUUnZnMDRzS2VLU2pCa3N6bEZyQXB3bGg1Vi0yQkpla1BOcnk5NE1xbERqOFdpYUR0ZU1yMjNhMUI5TUFkY1E3NDNMX3RjU2xqNUdMeWdvRlJVbHJXTGlERVQzQkplT205d3FMbDhKUWxsdjBWTDJvMjNOTjJhYmFBVmlPRnBBN1JXaEtIMjRZQWE2eHNjdjU2NEhDdFk4cng2c1Z5OG81a0JMWEVqaFh0cl91dzdORUJORmdUVTRpTV9TZDUwNEJqYUpUOWhETkp4N0RZQkxDRTlrczk1TXRoM0d4WUVDSjhJRnh3Tkw5QWJFUUd1YzFzUGhhWE1VTC1kb2pxc2pCLWRXM0NSLUhxdFlaWXlCdHZ2UDkwbUpSQzJ0b05CcGwwWjFNV1Vjd1RPSjlhN0Ryb3NnU1hnY1R2YVpiZ2d3NDhNazZwTHdxSlNQY1gwTlk5alByKgAyBVo1MTEwOg7miJDlip8gKFo1MTEwKQ==\",\"authType\":\"ZFACE\",\"ENV\":\"0\",\"C2S_PUB_KEY\":\"MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAvg78EIG7CKTV+FLotCu/4hJgbhPukVU1Ui8uk3tlDArt8zD8q4SH+lBovaOchxeyamSQ0HK3NgvgTIcfDhFcONETTzNr1F9aI1jiikvJC6Tx5W4va7N9UDB8+r5O362kRrttAB73pyebgAiD932Vn1hE9e31BT8Jq0+x1AEeKAl0lSKwf9AmnqnClSI/87kHjEJ2fVSLCGR93ss09lvjwaby+1bJKRZHToy5Rdto/fMVg4vn/vl4CxvqrIjELjAN1pqNM/0WXoJzopogobKSUxxGRoEN1DQgf4by30KvGxHjS71qAJvZ02N5F3ybGRug3v77MrmsQybhUBB9q4OY9QIDAQAB\",\"REMOTELOG_URL\":\"https://sg-sandbox-api.zoloz.com/loggw/logUpload.do\"},\"tasks\":[{\"inputParams\":{\"zimId\":{\"value\":\"faceZimId\",\"pipeType\":\"context\"},\"zimInitResp\":{\"value\":\"zimInitResp\",\"pipeType\":\"context\"},\"validateDelegate\":{\"value\":false,\"pipeType\":\"constant\"},\"useDefaultExit\":{\"value\":true,\"pipeType\":\"constant\"}},\"name\":\"ZFace\",\"index\":1,\"type\":\"nativeTask\"}]}"
        var bizConfig: [String: Any] = [:]
        guard let view = view as? UIViewController else { return }
        bizConfig[kZLZCurrentViewControllerKey] = view
        bizConfig[kZLZPubkey] = "publicKey"
        bizConfig[kZLZLocaleKey] = "ID"
        
        let request = ZLZRequest(zlzConfig: clientCfg, bizConfig: bizConfig)
        handle(request: request)
    }
    
    func handle(request: ZLZRequest) {
        DispatchQueue.main.async {
            ZLZFacade.sharedInstance().start(with: request, completeCallback: { response in
                print("resp: \(response)")
//                var parameterEvent: [String: String] = [:]
//                parameterEvent["ret_code"] = response.retcode
//                parameterEvent["ext_info"] = String("\(response.extInfo)")
//                AnalyticUtil.shared.logEvent(eventName: "face_verif_zoloz_start_completed", parameters: parameterEvent)
//                self.putZolozVerification()
            }) { interrupt in
//                var parameterEvent: [String: String] = [:]
//                parameterEvent["ret_code"] = interrupt.retcode
//                parameterEvent["ext_info"] = String("\(interrupt.extInfo)")
//                AnalyticUtil.shared.logEvent(eventName: "face_verif_zoloz_start_failed", parameters: parameterEvent)
//                self.navigateBack()
            }
        }
    }

}

extension ZolozPresenter: ZolozInteractorToPresenter {
    
}
