//
//  ZolozPresenter.swift
//  Zoloz
//
//  Created by Reynaldo Cristinus Hutahaean on 14/08/23.
//

import Foundation
import CommonZoloz

class ZolozPresenter {
    weak var view: ZolozPresenterToView?
    var interactor: ZolozPresenterToInteractor?
    var router: ZolozPresenterToRouter?
}

extension ZolozPresenter: ZolozViewToPresenter {
    func didTappedButton() {
    }
}

extension ZolozPresenter: ZolozInteractorToPresenter {
    
}
