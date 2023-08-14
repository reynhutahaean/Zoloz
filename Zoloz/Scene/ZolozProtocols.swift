//
//  ZolozProtocols.swift
//  Zoloz
//
//  Created by Reynaldo Cristinus Hutahaean on 14/08/23.
//

import Foundation

protocol ZolozPresenterToView: AnyObject {
    var presenter: ZolozViewToPresenter? { get set }
}

// MARK: Interactor -
protocol ZolozPresenterToInteractor: AnyObject {
    var presenter: ZolozInteractorToPresenter? { get set }
}

// MARK: Router -
protocol ZolozPresenterToRouter {
}

// MARK: Presenter -
protocol ZolozViewToPresenter: AnyObject {
    var view: ZolozPresenterToView? { get set }
    var interactor: ZolozPresenterToInteractor? { get set }
    var router: ZolozPresenterToRouter? { get set }
    
    func didTappedButton()
}

protocol ZolozInteractorToPresenter: AnyObject {

}
