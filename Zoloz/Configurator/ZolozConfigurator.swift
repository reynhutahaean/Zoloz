//
//  ZolozConfigurator.swift
//  Zoloz
//
//  Created by Reynaldo Cristinus Hutahaean on 14/08/23.
//

import UIKit

public class ZolozConfigurator {
    
    public static let shared = ZolozConfigurator()
    public weak var delegate: ZolozWireframe?
    
    public func createModule(clientCfg: String) -> UIViewController {
        let view: UIViewController & ZolozPresenterToView = ZolozViewController()
        let interactor: ZolozPresenterToInteractor = ZolozInteractor()
        let presenter: ZolozInteractorToPresenter & ZolozViewToPresenter = ZolozPresenter(clientCfg: clientCfg)
        let router: ZolozPresenterToRouter = ZolozRouter()
        
        view.presenter = presenter
        presenter.view = view
        presenter.interactor = interactor
        presenter.router = router
        interactor.presenter = presenter
        
        return view
    }
}
