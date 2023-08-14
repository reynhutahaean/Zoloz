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
        ZLZFacade.getMetaInfo()
//        startZoloz()
    }
    
    func startZoloz() {
        #warning("hardcoded public key and locale still use static value")
        let clientCfg = ""
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
